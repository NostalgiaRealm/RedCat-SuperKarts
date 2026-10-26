/*
 * FUN_0043885c at 0043885c
 * undefined __register FUN_0043885c(int * param_1, int * param_2)
 * Address ranges: 0043885c-004388d3
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0043885c(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_0042618c);
  if ((char)uVar1 == '\0') {
    FUN_0040fd8c(param_1,param_2);
  }
  else {
    FUN_00426a80(param_2,CONCAT31((int3)((uint)extraout_EDX >> 8),
                                  *(undefined1 *)((int)param_1 + 0x2d)));
    FUN_00426ad8(param_2,param_1[0x12]);
    FUN_00426b30(param_2,(uint *)param_1[0x13]);
    FUN_00426b98(param_2,param_1[0xd]);
    FUN_004269c0(param_2,(uint *)param_1[9]);
    FUN_00426c4c(param_2,CONCAT31((int3)((uint)extraout_EDX_00 >> 8),
                                  *(undefined1 *)((int)param_1 + 0x32)));
    (**(code **)(*param_2 + 0x34))();
  }
  return;
}

