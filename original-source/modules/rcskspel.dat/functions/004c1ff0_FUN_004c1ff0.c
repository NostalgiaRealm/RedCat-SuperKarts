/*
 * FUN_004c1ff0 at 004c1ff0
 * undefined FUN_004c1ff0(void)
 * Address ranges: 004c1ff0-004c2004
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

unkbyte10 FUN_004c1ff0(void)

{
  float10 in_ST0;
  float10 fVar1;
  unkbyte10 Var2;
  
  fVar1 = (float10)f2xm1(-(ROUND(in_ST0) - in_ST0));
  Var2 = fscale((float10)1 + fVar1,ROUND(in_ST0));
  return Var2;
}

