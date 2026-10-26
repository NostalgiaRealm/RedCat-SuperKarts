/*
 * FUN_00457ab0 at 00457ab0
 * undefined FUN_00457ab0(void)
 * Address ranges: 00457ab0-00457b58
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __thiscall FUN_00457ab0(int param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_004afce0(s___finding_ai_004f2448);
  iVar1 = FUN_004576b0(param_2);
  if (-1 < iVar1) {
    FUN_004afce0(s___detaching_004f2458);
    param_1 = iVar1 * 0x10 + param_1;
    *(undefined1 *)(param_1 + 0xc) = 0;
    iVar1 = DAT_006a5c38 + *(int *)(param_1 + 8) * 0xa9;
    *(undefined4 *)(iVar1 + 0x50) = 0;
    *(undefined4 *)(iVar1 + 0x54) = 0;
    *(undefined4 *)(iVar1 + 0x58) = 0;
    *(undefined4 *)(*(int *)(param_1 + 4) * 0xd0 + 0x44 + DAT_0067ee20) = 0;
    FUN_0048fea0(*(undefined4 *)(param_1 + 4));
    *(undefined4 *)(param_1 + 4) = 0xffffffff;
    return 1;
  }
  return 0;
}

