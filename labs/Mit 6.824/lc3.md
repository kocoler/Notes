LC03 GFS

### GFS
GFS: single master
master data:
- file name -> array of chunk handles(chunk ID) (NV)
- chunk ID -> list of chunk servers, version(NV), primary chunk(all write operation must on primary chunk), lease expiration time(for primary chunk)
NV is non-volatile

append log, create checkpoing timing


CS behavior:
1. c send name, offset(one chunk, cross chunk will slipt in two ...) to master
2. mester send back chunk handle(one), list of servers(for that chunk). c will cache those
3. c request data ..., servace response data ...

### Others

- Active-Standby failover
    lc says GFS's single master using avtive-standby failover mode
    active-standby failover mode is: two machine, has the same conf(standby will sync timing), when active machine is down, standby will take over(some says acquires active IP address and MAC, but some says that is host-standby failover, active-standy failover is using different IP address ...)

    ref:
    https://www.grandmetric.com/knowledge-base/design_and_configure/cisco-asa-active-standby-failover-design/
    https://www.draytek.com/support/knowledge-base/5406#linux
