/*
 * FUN_0049d570 at 0049d570
 * undefined FUN_0049d570(void)
 * Address ranges: 0049d570-0049d5d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0049d570(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0049d870();
  if (iVar1 != 0) {
    FUN_0049f2a0(*(int *)(param_1 + 0x54) != 0,s__s___d__Sound_engine_not_yet_att_004fbd90,
                 s___csndsrc_h_004fbd0c,0xc4);
    uVar2 = FUN_0049d520((*(int *)(*(int *)(param_1 + 0x54) + 0x270) * *(int *)(param_1 + 0x48)) /
                         100);
    FUN_004b4910(*(undefined4 *)(param_1 + 0x38),uVar2);
  }
  return;
}

