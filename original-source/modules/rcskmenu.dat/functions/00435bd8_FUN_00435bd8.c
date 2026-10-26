/*
 * FUN_00435bd8 at 00435bd8
 * undefined __register FUN_00435bd8(undefined * param_1)
 * Address ranges: 00435bd8-00435cb2
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00435bd8(undefined *param_1)

{
  undefined4 uVar1;
  int iVar2;
  ushort uVar3;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined *local_c;
  undefined *local_8;
  
  local_c = (undefined *)0x0;
  puStack_1c = (undefined1 *)0x435bf1;
  local_8 = param_1;
  FUN_00403f84((int)param_1);
  puStack_20 = &LAB_00435cb3;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puStack_1c = &stack0xfffffffc;
  do {
    do {
      uVar1 = FUN_00435b7c((int *)&local_8,DAT_0047b85c);
    } while ((char)uVar1 != '\0');
    uVar1 = FUN_00435b7c((int *)&local_8,&DAT_00435ccc);
  } while ((((char)uVar1 != '\0') ||
           (uVar1 = FUN_00435b7c((int *)&local_8,DAT_0047b860), (char)uVar1 != '\0')) ||
          (uVar1 = FUN_00435b7c((int *)&local_8,DAT_0047b864), (char)uVar1 != '\0'));
  if (local_8 != (undefined *)0x0) {
    uVar3 = 8;
    do {
      FUN_00435978(uVar3,(int *)&local_c);
      iVar2 = FUN_00407db0(local_8,local_c);
      if (iVar2 == 0) break;
      uVar3 = uVar3 + 1;
    } while (uVar3 != 0x256);
  }
  *in_FS_OFFSET = uStack_24;
  puStack_1c = &LAB_00435cba;
  puStack_20 = (undefined1 *)0x435cb2;
  FUN_00403b74((int *)&local_c,2);
  return;
}

