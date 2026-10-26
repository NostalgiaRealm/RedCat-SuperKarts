/*
 * FUN_0046434c at 0046434c
 * undefined __register FUN_0046434c(int * param_1)
 * Address ranges: 0046434c-004643d9
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_0046434c(int *param_1)

{
  undefined4 *in_FS_OFFSET;
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined1 *puStack_28;
  undefined *local_20;
  tagRECT local_1c;
  tagSIZE local_c;
  
  puStack_28 = &stack0xfffffffc;
  local_20 = (undefined *)0x0;
  puStack_2c = &LAB_004643da;
  uStack_30 = *in_FS_OFFSET;
  *in_FS_OFFSET = &uStack_30;
  FUN_00463ecc(param_1,&local_1c);
  OffsetRect(&local_1c,-2,0);
  FUN_0043f64c((int)param_1,(int *)&local_20);
  FUN_004187b0((int *)param_1[0x83],local_20,&local_c);
  local_1c.right = local_1c.left + local_c.cx + 5;
  InflateRect(&local_1c,-1,-1);
  local_1c.bottom = local_1c.bottom + 1;
  FUN_00418504((int *)param_1[0x83],&local_1c);
  *in_FS_OFFSET = uStack_30;
  puStack_28 = &LAB_004643e1;
  puStack_2c = (undefined1 *)0x4643d9;
  FUN_00403b50((int *)&local_20);
  return;
}

