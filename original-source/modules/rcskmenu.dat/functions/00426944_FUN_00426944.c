/*
 * FUN_00426944 at 00426944
 * undefined FUN_00426944(void)
 * Address ranges: 00426944-004269bd
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00426944(int *param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined2 extraout_var;
  undefined4 extraout_EDX_01;
  
  uVar1 = FUN_00403024(param_2,(int)&PTR_FUN_0042618c);
  if ((char)uVar1 == '\0') {
    FUN_0040fd8c(param_1,param_2);
  }
  else {
    FUN_004269c0(param_2,(uint *)param_1[0x15]);
    FUN_00426a28(param_2,CONCAT31((int3)((uint)extraout_EDX >> 8),(char)param_1[0x16]));
    FUN_00426a80(param_2,CONCAT31((int3)((uint)extraout_EDX_00 >> 8),
                                  *(undefined1 *)((int)param_1 + 0x59)));
    FUN_00426ad8(param_2,param_1[0x17]);
    FUN_00426b30(param_2,(uint *)param_1[0x18]);
    FUN_00426b98(param_2,param_1[0x19]);
    FUN_00426bf0(param_2,CONCAT22(extraout_var,(short)param_1[0x1a]));
    FUN_00426c4c(param_2,CONCAT31((int3)((uint)extraout_EDX_01 >> 8),
                                  *(undefined1 *)((int)param_1 + 0x6a)));
  }
  return;
}

