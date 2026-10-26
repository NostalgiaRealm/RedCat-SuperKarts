/*
 * FUN_0040322f at 0040322f
 * undefined4 __cdecl FUN_0040322f(int param_1)
 * Address ranges: 0040322f-0040330c
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040322f(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *local_78;
  undefined4 local_70 [27];
  
  if ((DAT_00438468 == 0) || (param_1 != 0)) {
    if (param_1 == 0) {
      local_78 = DAT_00438434;
    }
    else if (param_1 == 1) {
      local_78 = DAT_00438438;
    }
    else if (param_1 == 2) {
      local_78 = DAT_00438418;
    }
    else {
      FUN_0040187a((byte *)s__s__d____unidentified_focus_erro_0042d588);
    }
    _memset(local_70,0,0x6c);
    local_70[0] = 0x6c;
    FUN_004028c2(local_78);
    iVar2 = (**(code **)(*local_78 + 100))(local_78,0,local_70,1,0);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*local_78 + 0x80))(local_78,0);
      if (iVar2 == 0) {
        uVar1 = 1;
      }
      else {
        uVar1 = 0;
      }
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

