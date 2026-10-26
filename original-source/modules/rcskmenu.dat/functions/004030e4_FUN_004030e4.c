/*
 * FUN_004030e4 at 004030e4
 * undefined FUN_004030e4(void)
 * Address ranges: 004030e4-00403109
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004030e4(int *param_1,ushort *param_2)

{
  ushort uVar1;
  undefined4 unaff_EBX;
  bool bVar2;
  
  uVar1 = *param_2;
  if ((uVar1 != 0) && (bVar2 = uVar1 == 0xc000, uVar1 < 0xc000)) {
    FUN_00403058(*param_1);
    if (!bVar2) {
                    /* WARNING: Could not recover jumptable at 0x00403102. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)CONCAT22((short)((uint)unaff_EBX >> 0x10),uVar1))();
      return;
    }
  }
                    /* WARNING: Could not recover jumptable at 0x00403107. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*param_1 + -0x10))();
  return;
}

