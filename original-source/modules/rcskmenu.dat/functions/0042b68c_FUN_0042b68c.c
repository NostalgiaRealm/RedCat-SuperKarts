/*
 * FUN_0042b68c at 0042b68c
 * undefined FUN_0042b68c(void)
 * Address ranges: 0042b68c-0042b6f1
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042b68c(int param_1,int *param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  
  FUN_004408ac(param_1,param_2);
  (**(code **)(*param_2 + 4))
            (param_2,"PixelsPerInch",
             CONCAT31((int3)((uint)extraout_ECX >> 8),*(undefined1 *)(param_1 + 0x4e)) ^ 1,
             &LAB_0042b790,param_1,0,0);
  (**(code **)(*param_2 + 4))
            (param_2,"TextHeight",
             CONCAT31((int3)((uint)extraout_ECX_00 >> 8),*(undefined1 *)(param_1 + 0x4e)) ^ 1,
             &LAB_0042b774,param_1,&LAB_0042b75c,param_1);
  (**(code **)(*param_2 + 4))(param_2,"IgnoreFontProperty",0,0,0,&LAB_0042b73c,param_1);
  return;
}

