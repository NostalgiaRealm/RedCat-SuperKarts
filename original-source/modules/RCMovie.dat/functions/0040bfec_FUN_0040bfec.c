/*
 * FUN_0040bfec at 0040bfec
 * undefined4 __cdecl FUN_0040bfec(int param_1)
 * Address ranges: 0040bfec-0040c329
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 __cdecl FUN_0040bfec(int param_1)

{
  HLOCAL pvVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_10;
  uint local_c;
  SIZE_T local_8;
  
  if ((param_1 < 0) || (DAT_00431b64 <= param_1)) {
    FUN_0040187a((byte *)s__s__d____index_out_of_mem_image_a_00431eac);
  }
  if (*(int *)(DAT_0043d6e8 + 8 + param_1 * 0x20) < 1) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_xsize____d___00431eec);
  }
  if (*(int *)(DAT_0043d6e8 + 0xc + param_1 * 0x20) < 1) {
    FUN_0040187a((byte *)s__s__d____illegal_mem_ysize____d___00431f24);
  }
  local_8 = *(int *)(DAT_0043d6e8 + 8 + param_1 * 0x20) *
            *(int *)(DAT_0043d6e8 + 0xc + param_1 * 0x20);
  iVar3 = *(int *)(DAT_0043d6e8 + 0x18 + param_1 * 0x20);
  if (iVar3 == 2) {
    if (DAT_0043d6dc == 0) {
      uVar2 = FUN_004028e3(*(undefined4 *)(DAT_0043d6e8 + 8 + param_1 * 0x20),
                           *(undefined4 *)(DAT_0043d6e8 + 0xc + param_1 * 0x20));
      *(undefined4 *)(DAT_0043d6e8 + 4 + param_1 * 0x20) = uVar2;
      if (*(int *)(DAT_0043d6e8 + 4 + param_1 * 0x20) == 0) {
        return 2000;
      }
    }
    else {
      uVar2 = FUN_004028e3(*(undefined4 *)(DAT_0043d6e8 + 8 + param_1 * 0x20),
                           *(undefined4 *)(DAT_0043d6e8 + 0xc + param_1 * 0x20));
      *(undefined4 *)(DAT_0043d6e8 + 4 + param_1 * 0x20) = uVar2;
      if (DAT_0043d6e4 == 0) {
        return 2000;
      }
    }
    if (DAT_0043d754 == 0) {
      local_c = DAT_0042c4d0;
    }
    else if (DAT_0043d754 == 4) {
      local_c = FUN_0040de93(DAT_00438474,0x18);
    }
    else {
      local_c = FUN_0040de93(DAT_0042c4d0,8);
    }
    local_10 = local_c;
    iVar3 = (**(code **)(**(int **)(DAT_0043d6e8 + 4 + param_1 * 0x20) + 0x74))
                      (*(undefined4 *)(DAT_0043d6e8 + 4 + param_1 * 0x20),8,&local_10);
    if (iVar3 != 0) {
      FUN_00401f61(iVar3);
      FUN_0040187a((byte *)s__s__d____failed_to_set_color_key_00431f9c);
    }
    *(undefined4 *)(DAT_0043d6e8 + 0x1c + param_1 * 0x20) = 1;
  }
  else if (iVar3 == 4) {
    if ((int)local_8 < 1) {
      FUN_0040187a((byte *)s__s__d____error_illegal_mem_image_00431f5c);
    }
    pvVar1 = LocalAlloc(0x40,local_8);
    *(HLOCAL *)(DAT_0043d6e8 + param_1 * 0x20) = pvVar1;
    if (*(int *)(DAT_0043d6e8 + param_1 * 0x20) == 0) {
      return 2000;
    }
    *(undefined4 *)(DAT_0043d6e8 + 0x1c + param_1 * 0x20) = 1;
  }
  else {
    FUN_0040187a((byte *)s__s__d____illegal_alloc_type__d_f_00431fd0);
  }
  return 0;
}

