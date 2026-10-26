/*
 * FUN_00473f6c at 00473f6c
 * undefined __register FUN_00473f6c(int * param_1)
 * Address ranges: 00473f6c-0047403a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00473f6c(int *param_1)

{
  char cVar1;
  int extraout_ECX;
  int extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_1c;
  undefined1 *puStack_18;
  undefined1 *puStack_14;
  undefined4 *local_c;
  undefined4 *local_8;
  
  puStack_14 = &stack0xfffffffc;
  local_8 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  puStack_18 = &LAB_0047403b;
  uStack_1c = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_1c;
  cVar1 = FUN_0045bba8(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c));
  if (cVar1 == '\x01') {
    FUN_0045c4c8(0x32,(int *)&local_8);
    cVar1 = FUN_00460d08(local_8);
    if (cVar1 == '\x01') {
      FUN_00474048();
      FUN_0045bbac(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c),5);
      (**(code **)**(undefined4 **)PTR_DAT_0047c740)();
      *(undefined1 *)(param_1 + 0xb5) = 4;
      FUN_0042eb18(param_1,extraout_EDX,extraout_ECX);
    }
  }
  else {
    FUN_0045c4c8(0x24,(int *)&local_c);
    cVar1 = FUN_00460d08(local_c);
    if (cVar1 == '\x01') {
      FUN_0045bbac(*(int *)(*(int *)PTR_DAT_0047c670 + 0x7c),5);
      (**(code **)**(undefined4 **)PTR_DAT_0047c740)();
      *(undefined1 *)(param_1 + 0xb5) = 4;
      FUN_0042eb18(param_1,extraout_EDX_00,extraout_ECX_00);
    }
  }
  *in_FS_OFFSET = uStack_1c;
  puStack_14 = &LAB_00474042;
  puStack_18 = (undefined1 *)0x47403a;
  FUN_00403b74((int *)&local_c,2);
  return;
}

