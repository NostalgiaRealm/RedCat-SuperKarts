/*
 * FUN_0047790c at 0047790c
 * int * __register FUN_0047790c(int * param_1, char param_2, undefined4 param_3)
 * Address ranges: 0047790c-00477995
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

int * FUN_0047790c(int *param_1,char param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined1 extraout_DL;
  undefined1 uVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 in_stack_ffffffe4;
  undefined4 in_stack_ffffffe8;
  undefined4 uStack_8;
  
  uVar2 = 0;
  uStack_8 = param_3;
  if (param_2 != '\0') {
    param_1 = (int *)FUN_004031ac((int)param_1,param_2,param_3,in_stack_ffffffe4,in_stack_ffffffe8);
    param_3 = extraout_ECX;
    uVar2 = extraout_DL;
  }
  uStack_8 = CONCAT13(uVar2,(undefined3)uStack_8);
  FUN_0045d414(param_1,'\0',param_3);
  FUN_00403ba4(param_1 + 0xb4,(undefined4 *)"PHASE_LANDINFO");
  FUN_004779f0((int)param_1);
  iVar1 = FUN_00458490(*(int *)(*(int *)PTR_DAT_0047c670 + 0x90),(undefined2 *)((int)&uStack_8 + 1),
                       *(int *)(*(int *)(*(int *)PTR_DAT_0047c670 + 0x80) + 0x14));
  *(undefined1 *)(param_1 + 0xcb) = uStack_8._1_1_;
  FUN_00477ac0((int)param_1,CONCAT31((int3)((uint)iVar1 >> 8),uStack_8._1_1_));
  if (uStack_8._3_1_ != '\0') {
    FUN_00403204(param_1);
    *in_FS_OFFSET = in_stack_ffffffe4;
  }
  return param_1;
}

