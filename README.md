# Password manager implementation in C
The title is very self-explanatory, tbh.

## Build
```bash
make out

# for debug
make debug

# clear
make clear
```

## Usage
```bash
./passgen <<< <how many characters> <<< <difficulty level: 0 or 1 or 2> | tail -n 1
````

Example:
```bash
./passgen <<< 10 <<< 2 | tail -n 1
````

You can pipe the result to your clipboard using `xclip` or similar tools like so:
```bash
./passgen <<< 10 <<< 2 | tail -n 1 | xclip -selection clipboard
````

You can these useful aliases to make copying and pasting in CLI easier.   
(At the end of your ~/.bashrc file):
```bash
# Copy to the clipboard
alias c='xclip -selection clipboard'
# Paste from the clipboard
alias p='xclip -selection clipboard -o'

# Navigate to the string path in the clipboard 
alias cdp='cd "$(p)"'
````

Hence the example could be simplified by running: 
```bash
./passgen <<< 10 <<< 2 | tail -n 1 | c
````

You can even add an alias that runs this whole command for whenever you need 
to generate a new password for a random website.
```bash
alias genpass='/path/to/passgen <<< 10 <<< 2 | tail -n 1 | c' 
```

