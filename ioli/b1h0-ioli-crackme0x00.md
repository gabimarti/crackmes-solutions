# [IOLI crackme0x00](crackme0x00.exe) 

## Crackme writeup by [@H0l3Bl4ck](https://twitter.com/H0l3Bl4ck) https://twitter.com/H0l3Bl4ck
#### Date: 06/abr/2020 

You can download **crackme0x00.exe** from this [link](crackme0x00.exe). 

We have here a simple executable that asks us for a password. Let's see how we discovered it.

![crackme_001](crackme0x00-001.png "Console") 

To analyze this file I have used only static analysis with **Ghidra**.

## Ghidra analysis

If we place ourselves in the **main()** function with Ghidra, we can quickly see after asking for the password, that a value is loaded in the stack with a text string, and then another value with the memory address where the password has already been entered Then the **_strcmp()** function is called. The first value loaded as a parameter is precisely the password we are looking for, which corresponds to the text string **"250382"**.

![crackme_002](crackme0x00-002.png "Ghidra") 

This is more evident even if we access the Decompiler tab where the code in C clearly reveals the comparison with that text string. So this crackme is solved simply. 

![crackme_003](crackme0x00-003.png "Decompile")

Let's see the result.

![crackme_004](crackme0x00-004.png "Result")

# That's all folks!


