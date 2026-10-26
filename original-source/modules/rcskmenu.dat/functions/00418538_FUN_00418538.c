/*
 * FUN_00418538 at 00418538
 * undefined __register FUN_00418538(int * param_1, RECT * param_2)
 * Address ranges: 00418538-0041856e
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00418538(int *param_1,RECT *param_2)

{
  HBRUSH hbr;
  
  (**(code **)(*param_1 + 0x10))();
  FUN_00418a68(param_1,9);
  hbr = (HBRUSH)FUN_00417ed4(param_1[5]);
  FillRect((HDC)param_1[1],param_2,hbr);
  (**(code **)(*param_1 + 0xc))();
  return;
}

