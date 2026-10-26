/*
 * FUN_0045427c at 0045427c
 * undefined FUN_0045427c(void)
 * Address ranges: 0045427c-004542d7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045427c(uint *param_1)

{
  char cVar1;
  undefined **ppuVar2;
  undefined4 *in_FS_OFFSET;
  bool bVar3;
  undefined4 uStack_20;
  undefined *puStack_1c;
  undefined1 *puStack_18;
  uint *puStack_8;
  
  puStack_18 = (undefined1 *)0x45428f;
  puStack_8 = param_1;
  FUN_00403f84((int)param_1);
  puStack_1c = &UNK_004542d8;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  cVar1 = '\0';
  bVar3 = true;
  ppuVar2 = &PTR_s_NEDERLAND_0047bc80;
  puStack_18 = &stack0xfffffffc;
  do {
    FUN_00403ee0((uint *)*ppuVar2,puStack_8);
    if (bVar3) break;
    cVar1 = cVar1 + '\x01';
    ppuVar2 = ppuVar2 + 1;
    bVar3 = cVar1 == '\x06';
  } while (!bVar3);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &UNK_004542df;
  puStack_1c = (undefined *)0x4542d7;
  FUN_00403b50((int *)&puStack_8);
  return;
}

