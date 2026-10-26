/*
 * FUN_00457704 at 00457704
 * undefined __register FUN_00457704(undefined4 * param_1, int * param_2)
 * Address ranges: 00457704-004577c7
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_00457704(undefined4 *param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_24;
  undefined1 *puStack_20;
  undefined1 *puStack_1c;
  undefined4 *local_14;
  undefined4 *local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_c = (undefined4 *)0x0;
  local_10 = (undefined4 *)0x0;
  local_14 = (undefined4 *)0x0;
  puStack_1c = (undefined1 *)0x45771b;
  local_8 = param_1;
  FUN_00403f84((int)param_1);
  puStack_20 = &LAB_004577c8;
  uStack_24 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_24;
  puStack_1c = &stack0xfffffffc;
  FUN_00403b50((int *)&local_10);
  puVar1 = local_8;
  FUN_00403e90((int *)&local_c,3);
  uVar2 = FUN_0040811c((undefined *)local_c);
  if ((char)uVar2 == '\0') {
    FUN_00403e1c((int *)&local_c,(undefined4 *)"\\media\\sounds\\",local_8);
    FUN_0045c7cc(local_c,(int *)&local_14);
    FUN_00403e1c((int *)&local_10,local_14,local_c);
    uVar2 = FUN_0040811c((undefined *)local_10);
    if ((char)uVar2 == '\0') {
      FUN_00403b50((int *)&local_10);
    }
  }
  else {
    FUN_00403be8((int *)&local_10,(int)local_c);
  }
  FUN_00403ba4(param_2,local_10);
  *in_FS_OFFSET = puVar1;
  FUN_00403b74((int *)&local_14,4);
  return;
}

