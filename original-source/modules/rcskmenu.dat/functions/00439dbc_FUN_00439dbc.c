/*
 * FUN_00439dbc at 00439dbc
 * int __register FUN_00439dbc(int param_1, HMENU param_2, UINT param_3, UINT param_4, int param_5, char * param_6)
 * Address ranges: 00439dbc-00439e62
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int FUN_00439dbc(int param_1,HMENU param_2,UINT param_3,UINT param_4,int param_5,char *param_6)

{
  undefined4 uVar1;
  UINT UVar2;
  int iVar3;
  undefined4 local_8;
  
  uVar1 = FUN_00439528(param_1);
  if ((char)uVar1 == '\0') {
    iVar3 = GetMenuStringA(param_2,param_3,param_6,param_5,param_4);
  }
  else {
    local_8 = 0;
    UVar2 = GetMenuState(param_2,param_3,param_4);
    if ((UVar2 & 0x10) == 0) {
      UVar2 = GetMenuItemID(param_2,param_3);
      if (UVar2 != 0xffffffff) {
        local_8 = FUN_004393f8(param_1);
      }
    }
    else {
      GetSubMenu(param_2,param_3);
      local_8 = FUN_004393f8(param_1);
    }
    if (local_8 == 0) {
      iVar3 = 0;
    }
    else {
      *param_6 = '\0';
      FUN_00408428(param_6,*(undefined **)(local_8 + 0x24),param_5);
      iVar3 = FUN_00408340(param_6);
    }
  }
  return iVar3;
}

