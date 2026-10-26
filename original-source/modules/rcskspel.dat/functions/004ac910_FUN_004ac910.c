/*
 * FUN_004ac910 at 004ac910
 * undefined FUN_004ac910(void)
 * Address ranges: 004ac910-004aca5a
 * Origin: Ghidra decompiler; identifiers and types may be inferred.
 */

void FUN_004ac910(uint param_1)

{
  char *_Dest;
  char *_Dest_00;
  undefined4 *puVar1;
  void *pvVar2;
  int iVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_004d18cb;
  local_c = ExceptionList;
  if (DAT_006a62ec == 0) {
    ExceptionList = &local_c;
    puVar1 = operator_new(0x46);
    local_4 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)0x0;
    }
    else {
      _Dest = (char *)(puVar1 + 5);
      puVar1[3] = 0;
      _strncpy(_Dest,s__d3d_viewport_ptr_004fdef4,0x19);
      _Dest_00 = (char *)((int)puVar1 + 0x2d);
      _strncpy(_Dest_00,s_viewport_t_004fdee8,0x19);
      if (puVar1[3] != 0) {
        if (puVar1[3] == 1) {
          FUN_004afce0(s_T_ARRAY___deleting___16_16s___16_004de718,_Dest_00,_Dest,puVar1[1]);
          FUN_004bc150(*puVar1);
        }
        if (puVar1[3] != 0) {
          FUN_004bc150(puVar1[4]);
          puVar1[3] = 0;
        }
        FUN_004afce0(s___done_deleting_T_ARRAY_004de6fc);
      }
      if ((int)param_1 < 0) {
        FUN_004afee0(s__s__d____T_ARRAY_construction__i_004de770,s___array_hpp_004fc894,0x107,
                     _Dest_00,_Dest,param_1);
      }
      pvVar2 = operator_new(param_1 * 4);
      *puVar1 = pvVar2;
      puVar1[1] = param_1;
      puVar1[2] = 0;
      pvVar2 = operator_new(param_1);
      puVar1[4] = pvVar2;
      FUN_004afce0(s_T_ARRAY___alloc___16_16s___16_16_004de744,_Dest_00,_Dest,puVar1[1]);
      iVar3 = 0;
      puVar1[3] = 1;
      if (0 < (int)param_1) {
        do {
          iVar3 = iVar3 + 1;
          *(undefined1 *)(puVar1[4] + -1 + iVar3) = 0;
        } while (iVar3 < (int)param_1);
      }
    }
    DAT_006a62ec = 1;
    DAT_006a62e8 = puVar1;
  }
  ExceptionList = local_c;
  return;
}

