/*
 * FUN_0041d4a0 at 0041d4a0
 * undefined FUN_0041d4a0(void)
 * Address ranges: 0041d4a0-0041d531
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041d4a0(int param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < 0) || (10 < param_1)) {
    FUN_004afee0(s__init_ai_cockpit_camera__illegal_004e2f54,param_1,10);
  }
  uVar1 = FUN_00498280();
  (&DAT_00508620)[param_1] = uVar1;
  FUN_00498a50(*(undefined4 *)(DAT_00505a28 * 0xd0 + 0xc + DAT_0067ee20),0,0x41580000,0);
  return;
}

