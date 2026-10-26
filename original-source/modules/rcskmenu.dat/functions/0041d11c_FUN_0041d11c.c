/*
 * FUN_0041d11c at 0041d11c
 * undefined __register FUN_0041d11c(int * param_1, short param_2, HBITMAP param_3, HPALETTE param_4)
 * Address ranges: 0041d11c-0041d19f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041d11c(int *param_1,short param_2,HBITMAP param_3,HPALETTE param_4)

{
  int iVar1;
  undefined4 local_58 [5];
  int local_44;
  undefined4 local_40;
  
  if ((param_2 != 2) || (param_3 == (HBITMAP)0x0)) {
    FUN_00418c54((undefined4 *)PTR_PTR_0047c87c);
  }
  FUN_0041cf04((int)param_1);
  FUN_00402b54(local_58,0x54,0);
  GetObjectA(param_3,0x54,local_58);
  if (local_44 == 0) {
    local_40 = 0;
  }
  FUN_0041c984((int)param_1,param_3,param_4,local_58);
  *(undefined1 *)(param_1[8] + 0x70) = 0;
  iVar1 = (**(code **)(*param_1 + 0x24))();
  *(bool *)((int)param_1 + 0x1a) = iVar1 != 0;
  (**(code **)(*param_1 + 0x10))(param_1,param_1);
  return;
}

