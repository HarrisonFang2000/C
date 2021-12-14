package com.neu.his.api.app.controller;

import com.neu.his.bms.service.BmsFeeQueryService;
import com.neu.his.common.api.CommonResult;
import com.neu.his.common.dto.app.AppCheckTestResult;
import com.neu.his.common.dto.app.AppDeptDescriptionResult;
import com.neu.his.common.dto.app.AppDrugItemResult;
import com.neu.his.common.dto.app.AppHistoryRegResult;
import com.neu.his.common.dto.dms.DmsRegHistoryResult;
import com.neu.his.dms.service.DmsNonDrugItemRecordService;
import com.neu.his.dms.service.DmsRegistrationService;
import com.neu.his.sms.SmsDescriptionService;
import io.swagger.annotations.Api;
import io.swagger.annotations.ApiOperation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import java.util.List;

@Controller
@Api(tags = "AppHistoryController", description = "APP 鎸傚彿鍘嗗彶淇℃伅绠＄悊")
@RequestMapping("/appRegHistory")
@CrossOrigin(allowCredentials = "true")
public class AppHistoryController {

    @Autowired
    private DmsRegistrationService dmsRegistrationService;

    @Autowired
    private BmsFeeQueryService bmsFeeQueryService;

    @Autowired
    private DmsNonDrugItemRecordService dmsNonDrugItemRecordService;

    @Autowired
    private SmsDescriptionService smsDescriptionService;

    /**
     * 鎻忚堪:鏌ヨ鍘嗗彶鎸傚彿淇℃伅鍒楄〃
     * <p>author: ma
     */
    @ApiOperation("鏌ヨ鍘嗗彶鎸傚彿淇℃伅")
    @RequestMapping(value = "/listAllRegistration", method = RequestMethod.POST)
    @ResponseBody
    public CommonResult<List<DmsRegHistoryResult>> listAllRegistration(@RequestParam("identificationNo") String identificationNo){
        List<DmsRegHistoryResult> list = dmsRegistrationService.listRegHistory(identificationNo);
        return CommonResult.success(list);
    }

    /**
     * 鎻忚堪:鏌ョ湅鏌愭鎸傚彿璐圭敤澶ч」
     * <p>author: ma
     */
    @ApiOperation("鏌ヨ鏌愭鎸傚彿璐圭敤锛堝ぇ椤癸級")
    @RequestMapping(value = "/listFee", method = RequestMethod.POST)
    @ResponseBody
    public CommonResult<List<AppHistoryRegResult>> listFee(@RequestParam("registrationId") Long registrationId){
        List<AppHistoryRegResult> feeResultList = bmsFeeQueryService.listFeePrescription(registrationId);
        return CommonResult.success(feeResultList);
    }

    /**
     * 鎻忚堪:鏌ョ湅鏌愭鎸傚彿璐圭敤灏忛」
     * <p>author: ma
     */
    @ApiOperation("鏌ヨ鏌愭鎸傚彿璐圭敤锛堝皬椤癸級")
    @RequestMapping(value = "/listDetail", method = RequestMethod.POST)
    @ResponseBody
    public CommonResult<List<AppDrugItemResult>> listFeeDetail(@RequestParam("prescriptionId") Long prescriptionId ,
                                                               @RequestParam("type") int type){
        List<AppDrugItemResult> itemResultList = bmsFeeQueryService.listFeeItem(prescriptionId,type);
        return CommonResult.success(itemResultList);
    }

    /**
     * 鎻忚堪:鏌ョ湅妫€鏌ユ楠岀粨鏋�
     * <p>author: ma
     */
    @ApiOperation("鏌ヨ妫€鏌ユ楠岀粨鏋�")
    @RequestMapping(value = "/getResult", method = RequestMethod.POST)
    @ResponseBody
    public CommonResult<AppCheckTestResult> getResult(@RequestParam("id") Long id){
        AppCheckTestResult result = dmsNonDrugItemRecordService.appGetResult(id);
        return CommonResult.success(result);
    }

    /**
     * 鎻忚堪:鏌ヨ鎵€鏈夌瀹ゆ弿杩�
     * <p>author: ma
     */
    @ApiOperation("鏌ヨ鎵€鏈夌瀹ゆ弿杩�")
    @RequestMapping(value = "/getDeptDescription", method = RequestMethod.POST)
    @ResponseBody
    public CommonResult<List<AppDeptDescriptionResult>> getDeptDescription(){
        return CommonResult.success(smsDescriptionService.getDeptDescription());
    }

}
