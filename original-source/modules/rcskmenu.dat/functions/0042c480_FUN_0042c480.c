/*
 * FUN_0042c480 at 0042c480
 * int __register FUN_0042c480(int param_1)
 * Address ranges: 0042c480-0042c4ca
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0042c480(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if ((*(char *)(param_1 + 0x217) == '\x02') && (*(int *)(param_1 + 0x23c) != 0)) {
    iVar1 = FUN_004301d8(DAT_0047d774);
    if (-1 < iVar1 + -1) {
      iVar3 = 0;
      do {
        iVar2 = FUN_004301c4(DAT_0047d774,iVar3);
        if (*(char *)(iVar2 + 0x217) == '\x01') {
          iVar4 = iVar4 + 1;
        }
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return iVar4;
}

