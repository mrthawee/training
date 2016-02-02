//
//  ViewController.swift
//  ClickCount
//
//  Created by Thawee Techathamnukool on 1/28/16.
//  Copyright © 2016 Thawee Techathamnukool. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var CounterDisplay: UILabel!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    var counter:Int = 0
    
    @IBAction func clickMeButton(sender: UIButton) {
        counter++
        CounterDisplay.text = "\(counter)"
        
    }
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

