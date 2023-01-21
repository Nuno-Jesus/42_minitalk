# **Minitalk**
This project was graded <strong>125/100</strong>.


## 📒 **About**
Compiling an running a single program is fine, but have you run 2 programs and made them communicate? Have you worked with signals? What about bits manipulation?

## 🚨 **Disclaimer**
At 42, the C projects are built following a bunch of rules that enforce good coding style. Some of them are:

	- No for, do while, switch, case or goto are allowed
	- No more than 25 lines per function and 5 functions per file
	- No assigns and declarations in the same line (unless static)
	- No more than 5 variables in 1 function
	... 

## 🔧 **Implementation**

<table>
	<thead>
		<tr>
			<th>Part</th>
			<th>File Name</th>
			<th>Functionality</th>
		</tr>
	</thead>
	<tbody>
		<tr>
			<td rowspan = 5><strong>Mandatory</strong></td>
			<td>ft_printf/</td>
			<td>Contains the files from the ft_printf project</td>
		</tr>
		<tr>
			<td>includes/</td>
			<td>Contains the header files needed to include</td>
		</tr>
		<tr>
			<td>client.c</td>
			<td>The client file which is used to send the string to the server using signals</td>
		</tr>
		<tr>
			<td>server.c</td>
			<td>The server file which is used to receive the string and handle the signals sent from the client</td>
		</tr>
		<tr>
			<td>utils.c</td>
			<td>Contains utilitary functions developed exclusively for this project</td>
		</tr>
		<tr>
			<td rowspan = 2><strong>Bonus</strong></td>
			<td>client_bonus.c</td>
			<td>The client file which is used to send the string to the server using signals. Can also send emojis and should receive a signal at the end of the transmission</td>
		</tr>
		<tr>
			<td>server_bonus.c</td>
			<td>The server file which is used to receive the string and handle the signals sent from the client. It sends a signal at the end of the transmission</td>
		</tr>
	</tbody>
</table>


## 📦 **Compilation**
To compile the library you can either run `make` or `make bonus` in the terminal. Both `make` and `make bonus` will compile and link all files together.

The `make` rule will generate 2 executables called `client` and `server`, one for each of the needed programs.

The `make bonus` rule will generate 2 executables called `client_bonus` and `server_bonus`, one for each of the needed programs.

To run the programs, just run the following commands, each in a different terminal:

```sh
./server
```
```sh
./client [SERVER PID] [MESSAGE]
```
## 💫 **Testing**

This project was tested using manual revision only.


## 📞 **Contact me**

Feel free to ask me any questions through Slack (**ncarvalh**).

