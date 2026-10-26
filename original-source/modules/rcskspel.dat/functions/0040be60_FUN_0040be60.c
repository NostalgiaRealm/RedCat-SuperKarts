/*
 * FUN_0040be60 at 0040be60
 * undefined FUN_0040be60(void)
 * Address ranges: 0040be60-0040bf76
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_0040be60(int param_1)

{
  undefined4 *puVar1;
  float fVar2;
  char cVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  fVar2 = *(float *)((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0xa4 + DAT_0067ee20);
  if (fVar2 < 20.0) {
    return CONCAT22((short)((uint)DAT_0067ee20 >> 0x10),
                    (ushort)(fVar2 < 20.0) << 8 | (ushort)NAN(fVar2) << 10 |
                    (ushort)(fVar2 == 20.0) << 0xe);
  }
  cVar3 = FUN_00417e90(param_1);
  uVar4 = DAT_0053be60;
  if (cVar3 == '\0') {
    uVar4 = (&DAT_005081b8)[param_1 * 0x1c];
  }
  iVar5 = FUN_004105c0(uVar4);
  if (iVar5 != -1) {
    iVar5 = iVar5 * 0xd0 + DAT_0067ee20;
    puVar1 = (undefined4 *)(*(int *)(iVar5 + 0x24) * 0x50 + 8 + DAT_00680ae0);
    local_c = *puVar1;
    local_8 = puVar1[1];
    local_4 = puVar1[2];
    iVar5 = FUN_00493a40(*(undefined4 *)
                          ((&DAT_00503ef0)[param_1 * 0x47] * 0xd0 + 0x1c + DAT_0067ee20),
                         *(undefined4 *)(iVar5 + 0x1c));
    if ((iVar5 < 4) && (iVar5 = FUN_00406320((&DAT_00503ef0)[param_1 * 0x47],&local_c), iVar5 == 1))
    {
      return 1;
    }
    return 0;
  }
  return 0xffffff00;
}

