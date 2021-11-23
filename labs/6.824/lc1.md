LC01 Introduction

#### MapReduce

User could just write simple `map` and `reduce` functions to use MapReduce, take no account of distribution.

Use `map` function(input and some out put, output is k-v) => intermediate output => collection output to `reduce` => final result

- Job
    whole MapReduce compute called Job
    
- Task
    Each MapReduce call is called a Task => map task and reduce task compose mapreduce.

emit: belongs to map functions.
