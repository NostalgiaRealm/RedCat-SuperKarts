/*
 * FUN_0045d5e4 at 0045d5e4
 * undefined __register FUN_0045d5e4(uint * param_1)
 * Address ranges: 0045d5e4-0045d63f
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0045d5e4(uint *param_1)

{
  char cVar1;
  undefined **ppuVar2;
  undefined4 *in_FS_OFFSET;
  bool bVar3;
  undefined4 uStack_20;
  undefined1 *puStack_1c;
  undefined1 *puStack_18;
  uint *local_8;
  
  puStack_18 = (undefined1 *)0x45d5f7;
  local_8 = param_1;
  FUN_00403f84((int)param_1);
  puStack_1c = &LAB_0045d640;
  uStack_20 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_20;
  cVar1 = '\0';
  bVar3 = true;
  ppuVar2 = &PTR_s_PR_NONE_0047c2e0;
  puStack_18 = &stack0xfffffffc;
  do {
    FUN_00403ee0((uint *)*ppuVar2,local_8);
    if (bVar3) break;
    cVar1 = cVar1 + '\x01';
    ppuVar2 = ppuVar2 + 1;
    bVar3 = cVar1 == '\x17';
  } while (!bVar3);
  *in_FS_OFFSET = uStack_20;
  puStack_18 = &LAB_0045d647;
  puStack_1c = (undefined1 *)0x45d63f;
  FUN_00403b50((int *)&local_8);
  return;
}

