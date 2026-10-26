/*
 * FUN_0041dee0 at 0041dee0
 * undefined FUN_0041dee0(void)
 * Address ranges: 0041dee0-0041e0a7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041dee0(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  DAT_00508620 = FUN_00498280();
  DAT_004e3068 = DAT_0053be28;
  iVar2 = *(int *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20);
  iVar1 = DAT_006a5c38 + iVar2 + 0x50 + iVar2 * 0xa8;
  FUN_004988a0(*(undefined4 *)(DAT_006a5c38 + iVar2 + 0x50 + iVar2 * 0xa8),
               *(float *)(iVar1 + 4) + 15.0,*(undefined4 *)(iVar1 + 8));
  FUN_00498a50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0x41a00000,0xc3160000);
  FUN_00498b50(*(undefined4 *)(DAT_004e3068 * 0xd0 + 0xc + DAT_0067ee20),0,0x42480000,0);
  FUN_00498c00();
  uVar5 = 0x401ccccc;
  uVar4 = 0x401ccccc;
  uVar3 = 0x401ccccc;
  FUN_0041eb70(DAT_00508620);
  FUN_00498990(uVar3,uVar4,uVar5);
  *(undefined4 *)(DAT_00680ba0 + 0x80 + DAT_00508620 * 0x178) = 0;
  DAT_004e3064 = 1;
  FUN_0041e280(1);
  return;
}

