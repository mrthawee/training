//
//  ViewController.swift
//  Conditional
//
//  Created by Thawee Techathamnukool on 1/28/16.
//  Copyright © 2016 Thawee Techathamnukool. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    var clickCnt:Int = 0;

    @IBOutlet weak var label: UILabel!
    
    @IBAction func clickMe(sender: AnyObject) {
        clickCnt++
        updateLabel(clickCnt)
    }
    
    func updateLabel(cnt:Int) {
        if (cnt % 2 == 0) {
            label.text = "cnt is even : \(cnt)"
        } else {
            label.text = "cnt is odd : \(cnt)"
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        label.text = "\(clickCnt)"
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

