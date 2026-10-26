/*
 * FUN_00407efc at 00407efc
 * undefined4 __register FUN_00407efc(char * param_1)
 * Address ranges: 00407efc-00407f5e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00407efc(char *param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  uVar3 = 0;
  iVar2 = FUN_00403dd0((int)param_1);
  if ((iVar2 != 0) &&
     (((cVar1 = *param_1, (byte)(cVar1 + 0xbfU) < 0x1a || (cVar1 == '_')) ||
      ((byte)(cVar1 + 0x9fU) < 0x1a)))) {
    iVar2 = FUN_00403dd0((int)param_1);
    if (1 < iVar2) {
      iVar2 = iVar2 + -1;
      iVar4 = 2;
      do {
        cVar1 = param_1[iVar4 + -1];
        if (((9 < (byte)(cVar1 - 0x30U)) && (0x19 < (byte)(cVar1 + 0xbfU))) &&
           ((cVar1 != '_' && (0x19 < (byte)(cVar1 + 0x9fU))))) {
          return 0;
        }
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    uVar3 = 1;
  }
  return uVar3;
}

