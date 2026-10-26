/*
 * FUN_0040b8e8 at 0040b8e8
 * char * __register FUN_0040b8e8(byte * param_1, char param_2)
 * Address ranges: 0040b8e8-0040b927
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * FUN_0040b8e8(byte *param_1,char param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = FUN_004084b4((char *)param_1,param_2);
  while( true ) {
    if (pcVar1 == (char *)0x0) {
      return (char *)0x0;
    }
    uVar2 = FUN_0040b594(param_1,(int)pcVar1 - (int)param_1);
    if ((char)uVar2 == '\0') break;
    if ((char)uVar2 == '\x01') {
      pcVar1 = pcVar1 + 1;
    }
    pcVar1 = FUN_004084b4(pcVar1 + 1,param_2);
  }
  return pcVar1;
}

