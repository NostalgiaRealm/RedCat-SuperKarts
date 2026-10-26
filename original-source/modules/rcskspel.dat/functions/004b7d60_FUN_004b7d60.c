/*
 * FUN_004b7d60 at 004b7d60
 * undefined FUN_004b7d60(void)
 * Address ranges: 004b7d60-004b7e12
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

undefined4 FUN_004b7d60(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if ((param_1 < 0) || (DAT_00501110 <= param_1)) {
    FUN_004afee0(s__s__d____index_out_of_mem_image_a_00501004,
                 s_C__libraries_dxdraw_Sprite_cpp_00501114,0x15a,param_1);
  }
  iVar3 = param_1 * 0x20;
  iVar1 = *(int *)(iVar3 + 0x18 + DAT_006ab880);
  if (iVar1 == 2) {
    if (*(int *)(iVar3 + 0x1c + DAT_006ab880) != 0) {
      *(undefined4 *)(iVar3 + 0x1c + DAT_006ab880) = 0;
      piVar2 = *(int **)(iVar3 + 4 + DAT_006ab880);
      (**(code **)(*piVar2 + 8))(piVar2);
    }
  }
  else {
    if (iVar1 != 4) {
      FUN_004afee0(s__s__d____illegal_alloc_type__d_f_0050119c,
                   s_C__libraries_dxdraw_Sprite_cpp_00501114,0x16b,iVar1,param_1);
      return 0;
    }
    if (*(int *)(iVar3 + 0x1c + DAT_006ab880) != 0) {
      *(undefined4 *)(iVar3 + 0x1c + DAT_006ab880) = 0;
      FUN_004bff99(*(undefined4 *)(iVar3 + DAT_006ab880));
      return 0;
    }
  }
  return 0;
}

