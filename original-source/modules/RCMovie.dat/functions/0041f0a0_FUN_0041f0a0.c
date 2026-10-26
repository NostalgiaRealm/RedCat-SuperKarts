/*
 * FUN_0041f0a0 at 0041f0a0
 * CRect * __fastcall FUN_0041f0a0(CRect * param_1)
 * Address ranges: 0041f0a0-0041f0ba
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

CRect * __fastcall FUN_0041f0a0(CRect *param_1)

{
  CRect::CRect(param_1,0,0,0,0);
  *(undefined4 *)(param_1 + 0x10) = 0;
  return param_1;
}

