
![图 1](https://i.loli.net/2021/11/26/tSWI7qDPso1FHK8.png)  

### Figure2

The most important figure to implement the Raft.

Will be more detailed explin with lab going ...

#### State

Persistent on all servers:
- currentTerm
    latest term server has seen (initialized to 0 on first boot, increases monotonically)
- votedFor
    candidateId that received vote in current term (or null if none)
- log[]
    log entries; each entry contains command for state machine, and term when entry was received by leader (first index is 1)

volatile on all servers:
- commitIndex
    index of highest log entry known to be committed (initialized to 0, increases monotonically)
- lastApplied
    index of highest log entry applied to state machine (initialized to 0, increases monotonically)

volatile on leaders:
(reinitialized after election)
- nextIndex[]
    for each server, index of the next log entry to send to that server (initialized to leader last log index + 1)
- matchIndex[]
    for each server, index of highest log entry known to be replicated on server (initialized to 0, increases monotonically)


#### AppendEntries RPC

Arguments:
- term: leader’s term
- leaderId: to redirect clients
- prevLogIndex: index of log entry immediately preceding new ones
- prevLogTerm: term of prevLogIndex entry
- entries[]: log entries to store (**empty for heartbeat**; may send more than one for efficiency)
- leaderCommit: leader’s commitIndex

Results:
- term: currentTerm, for leader to update itself
- success: true if follower contained an entry matching prevLogIndex and prevLogTerm

Receiver implementation:
- Reply false if term < currentTerm
- Reply false if log doesn't contain an entry at prevLogIndex whose term matches prevLogTerm
- If an existing entry conflicts with a new one (same index but different terms), delete the existing entry and all that follow it
- Append any new entries not already in the log
- If leaderCommit > commitIndex, set commitIndex = min(leaderCommit, index of last new entry)


#### RequestVote RPC

Arguments:
- term: candidate's term
- candidateId: candidate requesting vote
- lastLogIndex: index of candidate’s last log entry
- lastLogTerm: term of candidate’s last log entry

Results:
- term: currentTerm, for candidate to update itself
- voteGranted: true means candidate received vote

Receiver implementation:
- Reply false if term < currentTerm
- If votedFor is null or candidateId, and **candidate’s log is at least as up-to-date as receiver’s log**, grant vote

Rules for Servers

All Servers:
- If commitIndex > lastApplied: increment lastApplied, apply log[lastApplied] to state machine
- If RPC request or response contains term T > currentTerm: set currentTerm = T, **convert to follower**

Followers:
- respond to RPCs from candidates and leaders
- if election timeout elapses without receiving AppendEntries RPC from current leader or granting vote to candidate: **convert to candidate**

Candidates:
- On conversion to candidate, start election
    - Increment currentTerm
    - Vote for self
    - Reset election timer
    - Send RequestVote RPCs to all other servers
- If votes received from majority of servers: become leader
- If AppendEntries RPC received from new leader: **convert to follower**
- If election timeout elapses: **start new election**

Leader:
- Upon election: send initial empty AppendEntries RPCs (heartbeat) to each server; *repeat during idle periods to prevent election timeouts*
- If command received from client: append entry to local log, respond after entry applied to state machine
- If last log index >= nextIndex for a follower: send AppendEntries RPC with log entries starting at nextIndex
    - If successful: update nextIndex and matchIndex for follower
    - If AppendEntries fails because of log inconsistency: decrement nextIndex and retry
- If there exists an N such that N > commitIndex, a majority of matchIndex[i] >= N, and log[N].term == currentTerm: set commitIndex = N


### Leader election

basic mechanism: heartbeat -> trigger a leader election

- Follower state
    - receives RPCs from leader or candidate
        keep follower state
        - first-come-first-served votes for candidate
    - reach election timeout
        become candidate
        -> incr term, change to candidate state
- Leader state
    - send periodic heartbeats(AppendEntries RPC, carry no log entries)
    - 
- Candidate state
    - vote workflow:
        - votes for itself
        - issues RequestVote RPCs *in parallel* to other servers
        ---
        - if majority votes, become leader(*same term*)
            -> then send heartbeats to other servers
        - another server become leader
            receive heartbeat from new leader
        - a period of time ges by with no winner
            raft use randomized election timeouts (e.g.,150-300ms, candidate restarts randomized election timeout at the start of an election) to avoid
            
