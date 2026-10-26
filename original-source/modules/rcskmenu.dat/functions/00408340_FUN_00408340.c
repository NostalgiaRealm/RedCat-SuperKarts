/*
 * FUN_00408340 at 00408340
 * int __register FUN_00408340(char * param_1)
 * Address ranges: 00408340-00408356
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00408340(char *param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = -1;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *param_1;
    param_1 = param_1 + 1;
  } while (cVar1 != '\0');
  return -2 - iVar2;
}

