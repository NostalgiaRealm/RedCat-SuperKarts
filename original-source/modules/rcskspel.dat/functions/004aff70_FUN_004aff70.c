/*
 * FUN_004aff70 at 004aff70
 * undefined FUN_004aff70(void)
 * Address ranges: 004aff70-004b00b8
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004aff70(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  tagPOINT local_28;
  tagRECT local_20;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  cVar1 = FUN_004afcb0();
  if (cVar1 == '\0') {
    local_28.x = 0;
    local_28.y = 0;
  }
  else {
    GetClientRect(DAT_006a64b4,&local_20);
    local_28.x = local_20.left;
    local_28.y = local_20.top;
    ClientToScreen(DAT_006a64b4,&local_28);
  }
  local_20.right = local_20.right + local_28.x;
  local_20.bottom = local_20.bottom + local_28.y;
  local_8 = DAT_004fe930;
  local_10 = 0;
  local_c = 0;
  local_4 = DAT_004fe934;
  local_20.left = local_28.x;
  local_20.top = local_28.y;
  if (DAT_004fe940 == 0) {
    FUN_004b08e0(DAT_006a64bc);
    FUN_004b08e0(DAT_006a64c0);
    iVar2 = (**(code **)(*DAT_006a64bc + 0x14))
                      (DAT_006a64bc,&local_20,DAT_006a64c0,&local_10,0x1000000,0);
    if (iVar2 != 0) {
      uVar3 = FUN_004b0190(iVar2);
      FUN_004afee0(s__s__d____blitting_error___s___004feb9c,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x53f,uVar3);
    }
  }
  else {
    FUN_004b08e0(DAT_006a64bc);
    FUN_004b08e0(DAT_006a64c0);
    iVar2 = (**(code **)(*DAT_006a64bc + 0x2c))(DAT_006a64bc,0,1);
    if (iVar2 != 0) {
      uVar3 = FUN_004b0190(iVar2);
      FUN_004afee0(s__s__d____error_flipping_surfaces_004febbc,
                   s_C__libraries_dxdraw_Initlib_cpp_004feb14,0x534,uVar3);
      return;
    }
  }
  return;
}

