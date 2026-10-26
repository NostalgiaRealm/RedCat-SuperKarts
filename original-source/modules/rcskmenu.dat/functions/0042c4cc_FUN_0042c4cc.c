/*
 * FUN_0042c4cc at 0042c4cc
 * int __register FUN_0042c4cc(int param_1, int param_2)
 * Address ranges: 0042c4cc-0042c51a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_0042c4cc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((*(char *)(param_1 + 0x217) == '\x02') && (*(int *)(param_1 + 0x23c) != 0)) &&
     (iVar1 = FUN_004301d8(DAT_0047d774), -1 < iVar1 + -1)) {
    iVar3 = 0;
    do {
      iVar2 = FUN_004301c4(DAT_0047d774,iVar3);
      if ((*(char *)(iVar2 + 0x217) == '\x01') && (param_2 = param_2 + -1, param_2 < 0)) {
        return iVar2;
      }
      iVar3 = iVar3 + 1;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return 0;
}

