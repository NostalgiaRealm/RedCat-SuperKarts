/*
 * FUN_0042d360 at 0042d360
 * undefined FUN_0042d360(void)
 * Address ranges: 0042d360-0042d40a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042d360(void)

{
  int iVar1;
  float10 fVar2;
  undefined4 local_1c [7];
  
  local_1c[1] = 0x8e;
  local_1c[5] = 0x8e;
  local_1c[0] = 0;
  local_1c[2] = 0;
  local_1c[3] = 0x6e;
  local_1c[4] = 0;
  local_1c[6] = 0;
  FUN_0042a670(0,(&DAT_0053a730)[DAT_0053b9b4 * 0x25] * 1000,0);
  fVar2 = (float10)FUN_00415cf0(DAT_0053be2c);
  _DAT_0053d334 = FUN_0042d300((float)fVar2,local_1c[DAT_0053b9b4]);
  FUN_0042a670(8,_DAT_0053d334,1);
  iVar1 = FUN_0042abc0();
  if (iVar1 == 1) {
    FUN_0042a670(0x12,DAT_0053d2b0,1);
  }
  return;
}

