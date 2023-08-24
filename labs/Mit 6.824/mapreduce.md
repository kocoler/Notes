

![图 1](https://i.loli.net/2021/11/19/MXHZmdx41PeEjaY.png)  

### workflow:

input data split input into M partitions, intermediate key to R pieces using a partitioning function(specified by the user)

1. splits input into M pieces(16 - 64 MB, controlled by user optional parameter)

2. master
    assign work to workers(map or reduce task)

3. worker(map)
    parses key/value pairs out of the input data
    passes each pair to the user-defined Map function
    *buffer results in memory*

4. worker(map)
    buffer is partitioned into R regions by partitioning function

5. worker(reduce)
    use **remote procedure call** to communicate with map workers(?)
    read all ...
    sort by the intermediate key(group)

6. worker(reduce)
    iterates over the sorted intermediate data
    => encounter
    => user Reduce function
    => append result ...

7. wait for all map and reduce tasks finished


#### Fault tolerance

- worker failure
    master pings every worker periodically -> check workers status(alive or dead)
    if worker failure, tasks will reset to `idle` status, and waiting for next scheduling
    - complete map task will re-executed(result on disk), and notify all reduce tasks(using those data)
    - complete reduce task will not re-executed(result on global fs)

- master failure
    > However, given that there is only a single master, its failure is unlikely; 
    => aborts the MapReduce operation

- atomic commit
    to achieve as the non-fault and sequential execution
    - when map is completed, the worker will send the names of R file to master, master will record in the master structure(if duplicate, will be ignored)
    - when reduce is completed, the worker will rename the output file to one final file(if multiple workers, multiple rename calls will executed)

- non-deterministic operation
    may e(R1) is one execution of map task,
    but e(R2) is another

*so ... those simple operations may solved this? but why called ... weaker semantics?*

=> didn't support two-phase commit so for the situation that cross-file consistency need deterministic function

#### Locality

- input data is managed by GFS
    64MB one block, typically 3 replicas
    master will schedule map tasks to the works that hold the replica of input data(to read locally, and save network bandwidth, if couldn't, schedule workers using the same network switch)

#### Task Granularity

M map tasks and R reduce tasks may be much larger than the workers to achieve better dynamic load balance and faster recover when worker failure, map worker could be a reduce worker if finished
> We often perform MapReduce computations with M = 200, 000 and R = 5, 000, using 2,000 worker machines.

M more(16 MB to 64 MB of input data), R less

#### Backup Tasks

(backup tasks means backup resources)
to avoid some machines low performance
when a MapReduce operation is close to completion, the master will schedule backup execution

### Refinements

#### Partitioning Function

user could specify a partitioning function -> R output

#### Ordering Guarantees

in given **partition**, the key-value pairs are ordered by the key(incr)

#### Combiner Function

user could specify a combiner function to merge partial results before send to network

#### Input and output types

reader interface

####  Skipping Bad Records

skip the record that may cause deterministic error
> Each worker process installs a signal handler that catches segmentation violations and bus errors.

stores a argument number in a global variable, when the user code generate a signal, the handler will tell master the record, and if more than one failure on a record, master will skip the record

#### Local Execution

make it facilitate to debug

#### Status Information

show some status to user

#### Counter

user could add counter in appropriate place, counter values will periodically propagated to mater(**piggybacked on the ping response**)

