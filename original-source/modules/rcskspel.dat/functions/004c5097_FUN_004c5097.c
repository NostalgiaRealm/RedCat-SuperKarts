/*
 * FUN_004c5097 at 004c5097
 * undefined FUN_004c5097(void)
 * Address ranges: 004c5097-004c50fb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_004c5097(undefined4 param_1,double param_2)

{
  uint uVar1;
  float10 fVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_004ca227(param_2,param_1,param_1);
  if ((uVar1 & 0x90) == 0) {
    fVar2 = (float10)__frnd(param_2);
    if ((double)fVar2 == param_2) {
      fVar2 = (float10)__frnd();
      if (fVar2 == (float10)(param_2 / 2.0)) {
        uVar3 = 2;
      }
      else {
        uVar3 = 1;
      }
      return uVar3;
    }
  }
  return 0;
}

