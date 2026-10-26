/*
 * FUN_0041f9b0 at 0041f9b0
 * undefined FUN_0041f9b0(void)
 * Address ranges: 0041f9b0-0041fabb
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0041f9b0(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = DAT_00508638 * 0x178;
  FUN_00498b50(*(undefined4 *)(DAT_0053be28 * 0xd0 + 0xc + DAT_0067ee20),0,0x41a00000,0);
  puVar1 = (undefined4 *)
           (DAT_00680b28 + 0x24 +
           *(int *)(DAT_0068021c + 4 + *(int *)(DAT_0053be28 * 0xd0 + 0x1c + DAT_0067ee20) * 4) *
           0x984);
  uVar2 = *puVar1;
  fVar3 = (float)puVar1[1];
  uVar4 = puVar1[2];
  if (*(int *)(iVar5 + DAT_00680ba0 + 0x74) != 0) {
    FUN_00498b20();
  }
  FUN_004988a0(uVar2,fVar3 + 20.0,uVar4);
  FUN_00498c00();
  FUN_0041d6c0(6);
  return;
}

