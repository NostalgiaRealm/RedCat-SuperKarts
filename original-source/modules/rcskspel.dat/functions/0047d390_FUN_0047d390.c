/*
 * FUN_0047d390 at 0047d390
 * undefined FUN_0047d390(void)
 * Address ranges: 0047d390-0047d3ce
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void __fastcall FUN_0047d390(int *param_1)

{
  char cVar1;
  
  FUN_004afce0(s______D_R_A_W_I_N_G_U_P______004f8750);
  cVar1 = FUN_0047d6a0();
  if (cVar1 != '\0') {
    (**(code **)(*param_1 + 0x14))(1);
    FUN_0047dab0();
    return;
  }
  (**(code **)(*param_1 + 0x14))(0);
  FUN_0047dab0();
  return;
}

