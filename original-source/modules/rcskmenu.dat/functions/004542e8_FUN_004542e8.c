/*
 * FUN_004542e8 at 004542e8
 * undefined FUN_004542e8(void)
 * Address ranges: 004542e8-00454343
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004542e8(uint *param_1)

{
  char cVar1;
  undefined **ppuVar2;
  undefined4 *in_FS_OFFSET;
  bool bVar3;
  undefined4 uStack_20;
  undefined *puStack_1c;
  undefined1 *puStack_18;
  uint *puStack_8;
  
  puStack_18 = (undefined1 *)0x4542fb;
  puStack_8 = param_1;
  FUN_00403f84((int)param_1);
  puStack_1c = &UNK_00454344;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  cVar1 = '\0';
  bVar3 = true;
  ppuVar2 = &PTR_s_NORMALRACE_0047bce8;
  puStack_18 = &stack0xfffffffc;
  do {
    FUN_00403ee0((uint *)*ppuVar2,puStack_8);
    if (bVar3) break;
    cVar1 = cVar1 + '\x01';
    ppuVar2 = ppuVar2 + 1;
    bVar3 = cVar1 == '\x05';
  } while (!bVar3);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &UNK_0045434b;
  puStack_1c = (undefined *)0x454343;
  FUN_00403b50((int *)&puStack_8);
  return;
}

