/*
 * FUN_0042f470 at 0042f470
 * undefined FUN_0042f470(void)
 * Address ranges: 0042f470-0042f4b7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0042f470(void)

{
  bool bVar1;
  float10 fVar2;
  
  if (DAT_0053b9c0 == 0) {
    bVar1 = DAT_0053b9f0 != 0;
    fVar2 = (float10)FUN_0048f4e0();
    if (((float10)1.0 / fVar2 < (float10)10.0) && ((int)((-(uint)bVar1 & 10) + 0xf) < DAT_0053b9d0))
    {
      DAT_0053b9d0 = DAT_0053b9d0 + -1;
    }
  }
  return;
}

