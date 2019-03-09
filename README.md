# DGram Chat Server

I made a chat server using datagram sockets.  

## Compile and Run

To run on any 42SV lab computer, download and edit makefile to change the name of the computer you will run the server on. If you open the makefile, this will be self-explanatory.  
Then   
`make server`   
`make client`  
  
Anyone can `make client`, but they still need to modify the makefile to point to the right server machine)  

Then  
`./client` or `./server`  

## Usage

The server has no commands. It can only be controlled by a client.  

The client has the following commands available:  
 - `\q`                     (quit)
 - `\username billy joe     (change username)
 - `\style ...              (change display style)

 The style options available are: red green yellow blue magenta cyan white bold dim underline blink reverse hidden black black-background red-background green-background yellow-background blue-background magenta-background cyan-background white-background

## Credits

All the code was written by me.