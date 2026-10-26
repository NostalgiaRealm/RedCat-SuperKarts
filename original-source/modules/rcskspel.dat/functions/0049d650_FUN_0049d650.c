/*
 * FUN_0049d650 at 0049d650
 * undefined FUN_0049d650(void)
 * Address ranges: 0049d650-0049d69a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0049d650(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_0049d870();
  if (iVar1 != 0) {
    FUN_0049f250(param_2,0xffffd8f0,10000,s_D__work_rcracer_oursoundlib_soun_004fbd4c,0x161);
    FUN_004b49d0(*(undefined4 *)(param_1 + 0x38),param_2);
    *(undefined4 *)(param_1 + 0x50) = param_2;
    return;
  }
  *(undefined4 *)(param_1 + 0x50) = param_2;
  return;
}

