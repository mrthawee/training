//
//  ViewController.swift
//  Methods
//
//  Created by Thawee Techathamnukool on 1/28/16.
//  Copyright © 2016 Thawee Techathamnukool. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    @IBOutlet weak var label: UILabel!
    var score:Int = 0
    
    func didScore(points:Int) {
        // score = score + 1
        // ++score
        // score++
        
        score += points
        
        label.text = "Score: \(score)"
    }
    
    
    @IBAction func defaultHit(sender: AnyObject) {
        didScore(1)
    }
    @IBAction func smallHit(sender: AnyObject) {
        didScore(2)
    }
    @IBAction func bigHit(sender: AnyObject) {
        didScore(5)
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        self.didScore(1)
        //self.didScore(5)
    
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

