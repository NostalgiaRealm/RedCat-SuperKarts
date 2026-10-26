/*
 * FUN_00471194 at 00471194
 * undefined FUN_00471194(void)
 * Address ranges: 00471194-00471268
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00471194(int param_1)

{
  undefined4 uVar1;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  undefined *puStack_2c;
  undefined1 *puStack_28;
  undefined4 *puStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 *puStack_c;
  undefined4 *puStack_8;
  
  puStack_28 = &stack0xfffffffc;
  puStack_20 = (undefined4 *)0x0;
  puStack_8 = (undefined4 *)0x0;
  puStack_c = (undefined4 *)0x0;
  puStack_2c = &UNK_00471269;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0x280;
  uStack_10 = 0x1e0;
  FUN_00403e1c((int *)&puStack_c,(undefined4 *)"\\media\\movies\\",*(undefined4 **)(param_1 + 0x2e8)
              );
  FUN_0045c7cc(puStack_c,(int *)&puStack_20);
  FUN_00403e1c((int *)&puStack_8,puStack_20,puStack_c);
  uVar1 = FUN_0040811c((undefined *)puStack_8);
  if ((char)uVar1 != '\0') {
    FUN_00403ba4((int *)(*(int *)(param_1 + 0x2d8) + 0x300),puStack_8);
    FUN_0046d36c(*(int **)(param_1 + 0x2d8));
    if ((*(int **)(param_1 + 0x2d8))[0xbb] == 0) {
      FUN_0046d694(*(int **)(param_1 + 0x2d8));
      FUN_0046e230(*(int *)(param_1 + 0x2d8),&uStack_1c);
    }
  }
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &UNK_00471270;
  puStack_2c = (undefined *)0x47125b;
  FUN_00403b50((int *)&puStack_20);
  puStack_2c = (undefined *)0x471268;
  FUN_00403b74((int *)&puStack_c,2);
  return;
}

