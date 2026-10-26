/*
 * FUN_0046e74c at 0046e74c
 * undefined __register FUN_0046e74c(undefined4 param_1, byte * param_2)
 * Address ranges: 0046e74c-0046e7d4
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046e74c(undefined4 param_1,byte *param_2)

{
  uint *puVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *in_FS_OFFSET;
  undefined1 uVar4;
  undefined4 uStack_28;
  undefined1 *puStack_24;
  undefined1 *puStack_20;
  uint *local_14;
  uint *local_10;
  undefined1 local_9;
  byte *local_8;
  
  local_10 = (uint *)0x0;
  local_14 = (uint *)0x0;
  puStack_20 = (undefined1 *)0x46e767;
  local_8 = param_2;
  FUN_00403f84((int)param_2);
  uVar4 = true;
  puStack_24 = &LAB_0046e7d5;
  uStack_28 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_28;
  local_9 = 0;
  cVar2 = '\x04';
  puVar3 = (undefined4 *)PTR_PTR_0047c5e0;
  puStack_20 = &stack0xfffffffc;
  do {
    FUN_00407ca8(local_8,(int *)&local_10);
    puVar1 = local_10;
    FUN_00407ca8((byte *)*puVar3,(int *)&local_14);
    FUN_00403ee0(puVar1,local_14);
    if ((bool)uVar4) {
      local_9 = 1;
      break;
    }
    puVar3 = puVar3 + 1;
    cVar2 = cVar2 + -1;
    uVar4 = cVar2 == '\0';
  } while (!(bool)uVar4);
  *in_FS_OFFSET = uStack_28;
  puStack_20 = &LAB_0046e7dc;
  puStack_24 = (undefined1 *)0x46e7cc;
  FUN_00403b74((int *)&local_14,2);
  puStack_24 = (undefined1 *)0x46e7d4;
  FUN_00403b50((int *)&local_8);
  return;
}

