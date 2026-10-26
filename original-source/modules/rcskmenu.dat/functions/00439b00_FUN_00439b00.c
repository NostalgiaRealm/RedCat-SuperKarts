/*
 * FUN_00439b00 at 00439b00
 * undefined4 __register FUN_00439b00(HMENU param_1, uint param_2, int param_3, byte param_4, int param_5)
 * Address ranges: 00439b00-00439b59
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_00439b00(HMENU param_1,uint param_2,int param_3,byte param_4,int param_5)

{
  UINT UVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if ((param_2 & 0x10) == 0) {
    UVar1 = GetMenuItemID(param_1,param_3);
    if (UVar1 != 0xffffffff) {
      iVar3 = FUN_004393f8(*(int *)(param_5 + -4));
    }
  }
  else {
    GetSubMenu(param_1,param_3);
    iVar3 = FUN_004393f8(*(int *)(param_5 + -4));
  }
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0042984c((uint)param_4,*(int *)(iVar3 + 0x24));
  }
  return uVar2;
}

