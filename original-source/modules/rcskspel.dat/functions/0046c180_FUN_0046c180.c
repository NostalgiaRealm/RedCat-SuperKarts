/*
 * FUN_0046c180 at 0046c180
 * undefined FUN_0046c180(void)
 * Address ranges: 0046c180-0046c1d2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __thiscall FUN_0046c180(int param_1,int param_2)

{
  int *piVar1;
  
  if (*(int *)(param_1 + 8) == 1) {
    FUN_0046cfb0();
  }
  piVar1 = (int *)FUN_0046c510();
  (**(code **)(*piVar1 + 0x50))(param_2);
  *(float *)(param_1 + 0x68) = (float)*(int *)(param_2 + 0x18);
  FUN_0046c670(*(undefined4 *)(param_2 + 0x10));
  FUN_0046c860(*(undefined4 *)(param_2 + 0x14));
  FUN_0046c890(0);
  FUN_0046c910();
  return;
}

