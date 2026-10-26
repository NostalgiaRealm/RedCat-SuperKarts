/*
 * FUN_0041e0b0 at 0041e0b0
 * undefined FUN_0041e0b0(void)
 * Address ranges: 0041e0b0-0041e269
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041e0b0(int param_1)

{
  int iVar1;
  int iVar2;
  
  DAT_004e3068 = param_1;
  FUN_00498b20();
  FUN_00498bd0();
  iVar2 = *(int *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20);
  iVar1 = DAT_006a5c38 + iVar2 + 0x50 + iVar2 * 0xa8;
  FUN_004988a0(*(undefined4 *)(DAT_006a5c38 + iVar2 + 0x50 + iVar2 * 0xa8),
               *(float *)(iVar1 + 4) + 15.0,*(undefined4 *)(iVar1 + 8));
  FUN_00498a50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0x41a00000,0xc3160000);
  FUN_00498b50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0x42480000,0);
  DAT_00508674 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
  DAT_00508648 = *(undefined4 *)(DAT_004e3068 * 0xd0 + 0x1c + DAT_0067ee20);
  FUN_0041e280(DAT_004e3064);
  return;
}

