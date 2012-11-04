README 
------

Execute a set of commands in a cluster of machines. 

Dependencies 
------------
i.  Package dependencies
1. sshpass for non interactive ssh based remote command execution.

ii. Logical dependencies
1. All the machines have a same login credentials.
2. Remote ssh is enabled in all the machines. 

 

Usage
-----
remoteExecute -u username -p password -c commandFile -h hostFiles

i. commandFile 
The set of instructions that are to be executed are kept this file with each command in a seperate line

eq: 

 :) (goofy:balaji)-(0)-(~/remoteCommand)

cat command.txt 

date
date

 :) (goofy:balaji)-(0)-(~/remoteCommand)

ii. hostFile
This file contains the ip addresses / hostnames of all the machines where the command is to be executed.
eq:
 :) (goofy:balaji)-(0)-(~/remoteCommand)

cat host.txt 

10.6.9.44
10.6.9.201

 :) (goofy:balaji)-(0)-(~/remoteCommand)


Sample command execution
------------------------
 :) (goofy:balaji)-(0)-(~/remoteExecute)                                     
remoteExecute -u <username> -p <password> -c command.txt  -h host.txt         
 :) (goofy:balaji)-(0)-(~/remoteExecute)                                      
Sun Nov  4 13:39:19 IST 2012                                                  
Sun Nov  4 13:39:19 IST 2012                                                  
Sun Nov  4 13:39:19 IST 2012                                                  
Sun Nov  4 13:39:19 IST 2012                                                   

-----
Please mail (sjbalajimdu@gmail.com) me if you find any bugs or need any additional features :).

