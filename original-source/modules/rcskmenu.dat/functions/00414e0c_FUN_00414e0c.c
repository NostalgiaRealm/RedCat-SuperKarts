/*
 * FUN_00414e0c at 00414e0c
 * undefined __register FUN_00414e0c(int param_1, undefined4 param_2, char param_3)
 * Address ranges: 00414e0c-00414e5a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00414e0c(int param_1,undefined4 param_2,char param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((char)param_2 == '\0') {
    *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x20) & 0xffef;
  }
  else {
    *(ushort *)(param_1 + 0x20) = *(ushort *)(param_1 + 0x20) | 0x10;
  }
  if (param_3 != '\0') {
    iVar1 = FUN_00414da8(param_1);
    if (-1 < iVar1 + -1) {
      iVar3 = 0;
      do {
        iVar2 = FUN_00414d7c(param_1,iVar3);
        FUN_00414e0c(iVar2,param_2,'\x01');
        iVar3 = iVar3 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
  }
  return;
}

