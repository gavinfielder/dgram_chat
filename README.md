# DGram Chat Server

I made a chat server using datagram sockets.  

## Compile and Run

To run on any 42SV lab computer, download and edit makefile to change the name of the computer you will run the server on. If you open the makefile, this will be self-explanatory.  
Then   
`make server`   
`make client`  
  
Anyone can `make client`, but they still need to modify the makefile to point to the right server machine)  

Then  
`./client` or `./server` or `./server -D` to run the server as daemon.  

## Usage

The server has no commands. It can only be controlled by a client.

The client has the following commands available:  
 - `\?` (show command list)
 - `\q`                      (quit)
 - `\username billy joe`     (change username)
 - `\style ...`              (change display style)
 - `\ping`                   (does a thing. Incidentally, it does the same thing if you send `ping`, or if you happen to figure out how to hack it to send it a raw `ping` datagram.)
 - A secret command for shutting down the server. You can find it in the source code.

 The style options available are: `red` `green` `yellow` `blue` `magenta` `cyan` `white` `bold` `dim` `underline` `blink` `reverse` `hidden` `black` `black-background` `red-background` `green-background` `yellow-background` `blue-background` `magenta-background` `cyan-background` `white-background`  
 You can mix and match style options, e.g. `\style red underline yellow-background`    

## Known Limitations

Some 42SV lab computers give you errno 49 "Protocol Driver not attached" error when trying to bind using UDP protocol. This simply can't be used on those machines.  

## Credits

All the code was written by me.
