/*
 * FUN_0040b8c0 at 0040b8c0
 * char * __register FUN_0040b8c0(byte * param_1, char param_2)
 * Address ranges: 0040b8c0-0040b8e7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

char * FUN_0040b8c0(byte *param_1,char param_2)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar2 = FUN_0040b8e8(param_1,param_2);
  pcVar3 = pcVar2;
  if (param_2 != '\0') {
    while (pcVar1 = pcVar3, pcVar1 != (char *)0x0) {
      pcVar3 = FUN_0040b8e8((byte *)(pcVar1 + 1),param_2);
      pcVar2 = pcVar1;
    }
  }
  return pcVar2;
}

